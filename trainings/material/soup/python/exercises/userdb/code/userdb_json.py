import json


def to_json(pyobj):
    return json.dumps(pyobj)

def from_json(jobj):
    return json.loads(jobj)
