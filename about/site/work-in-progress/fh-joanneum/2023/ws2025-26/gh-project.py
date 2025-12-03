#!/usr/bin/env python

import requests
import urllib

# list project fields

endpoint = 'https://api.github.com'
org = 'FH-STECE2023(Org)'
project_number = 3

url = f'{endpoint}/orgs/{urllib.parse.quote(org)}/projectsV2/{project_number}/fields'
print(url)

response = requests.get(f'{endpoint}/orgs/{urllib.parse.quote(org)}/projectsV2/{project_number}/fields')

print(response)
