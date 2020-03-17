def insert_switches(switches, cursor):
    for switch in switches:
        cursor.execute('INSERT INTO switches(name, uptime) values(?,?)', (switch.name, switch.uptime.total_seconds()))
        switchid = cursor.lastrowid
        for iface in switch.interfaces:
            cursor.execute('INSERT INTO interfaces(switch_id, name, number, adminstatus, operstatus, lastchange)'
                           ' values(?,?,?,?,?,?)',
                           (switchid, iface.name, iface.number,
                            iface.adminstatus, iface.operstatus, iface.last_change))
