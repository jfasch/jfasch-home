from .switch import Switch
from .interface import Interface 
from .error import MichisError

import datetime
import re


def parse_switch(name,
                 adminstatus_fname,
                 descr_fname,
                 lastchange_fname,
                 operstatus_fname,
                 snmpenginetime_fname):

    # parse file into dictionaries {str(ifnumber): whatever}
    admin_stati = parse_status(adminstatus_fname)
    descrs = parse_descr(descr_fname)
    last_changes = parse_lastchange(lastchange_fname)
    oper_stati = parse_status(operstatus_fname)
    # parse switch uptime
    uptime = parse_snmpenginetime(snmpenginetime_fname)

    # extract iface numbers from admin_stati, assuming that all the
    # others contain the same numbers
    iface_numbers = [ifnum for ifnum in admin_stati.keys()]

    # build the interface objects, hard-indexing all those
    # dictionaries
    ifaces = [Interface(number=ifnum, 
                        name=descrs[ifnum], 
                        adminstatus=admin_stati[ifnum], 
                        operstatus=oper_stati[ifnum], 
                        last_change=last_changes[ifnum])
              for ifnum in iface_numbers]

    return Switch(name, interfaces=ifaces, uptime=uptime)


def parse_status(fname):
    iface_stati = {} # {number: Interface.status}
    with open(fname) as f:
        for lineno, line in enumerate(f, start=1):
            path, eq, ty, stat = line.split()
            if eq != '=':
                raise MichisError('"=" required in line {} of {}'.format(lineno, fname))
            if ty != 'INTEGER:':
                raise MichisError('"INTEGER:" required in line {} of {}'.format(lineno, fname))
            _, num = path.rsplit('.', maxsplit=1)
            iface_stati[num] = int(stat)
    return iface_stati

def parse_descr(fname):
    iface_descrs = {} # {number: str(descr)}
    with open(fname) as f:
        for line in f:
            path, _, ty, stat = line.split()
            _, num = path.rsplit('.', maxsplit=1)
            iface_descrs[num] = eval(stat)
    return iface_descrs
    
def parse_lastchange(fname):
    iface_lastchanges = {} # {number: timedelta(lastchange)}
    with open(fname) as f:
        for lineno, line in enumerate(f, start=1):
            re_str = r'^.*\.(\d+)\s*=\s*Timeticks:\s*\((\d+)\)'
            match = re.search(re_str, line)
            if match is None:
                raise MichisError('{} nix match in line {} of {}'.format(re_str, lineno, fname))
            ifnum = match.group(1)
            time_100th_s = match.group(2)
            iface_lastchanges[ifnum] = datetime.timedelta(seconds=int(time_100th_s)/100)
    return iface_lastchanges

def parse_snmpenginetime(fname):
    with open(fname) as f:
        line = f.read()
        _,engtime = line.rsplit(maxsplit=1)
        return datetime.timedelta(seconds=int(engtime)/100)
