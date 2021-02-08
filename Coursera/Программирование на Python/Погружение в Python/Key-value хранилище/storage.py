#!/usr/bin/env python
# coding: utf-8

# In[23]:


import tempfile
import argparse
import os
import json
import os.path

storage_path = os.path.join(tempfile.gettempdir(), 'storage.data')
 
check_file = os.path.exists(storage_path)

if check_file:
    parser = argparse.ArgumentParser()
    parser.add_argument("--key")
    parser.add_argument("--value")
    parser.add_argument('--clear', action='store_true')
    args = parser.parse_args()
    if args.key and args.value:
        try:
            with open(STORAGE_PATH, 'r') as f:
                mass = f.read()
                if mass:
                    data = json.loads(mass)
        except Exception:
            data = []
        if args.key in data:
            data[args.key].append(args.value)
        else:
            data[args.key] = [args.value]
        with open(storage_path, 'w') as f:
            f.write(josn.dumps(data))
    if args.key and not args.value:
        try:
            with open(STORAGE_PATH, 'r') as f:
                mass = f.read()
                if mass:
                    data = json.loads(mass)
        except Exception:
            data = []
        if args.key in data:
            with open(storage_path, 'w') as f:
                f.write(josn.dumps(data[args.key]))
        else:
            print(None)
    if args.clear:
        os.remove(storage_path)
else:
    print(None)

