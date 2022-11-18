import os
import shutil
import pathlib

lists = os.listdir("./INPUT/")
Valid = [".inp", ".out", ".in"]

count = 1

for test in lists:
    print(test)
    try:
        files = os.listdir(f"./INPUT/{test}")
        for file in files:
            print(file)
            pre, ext = os.path.splitext(file)
            if ext in Valid:
                if ext == ".inp":
                    ext = ".in"
                shutil.copy(f"./INPUT/{test}/{file}", f"./OUTPUT/test{count}{ext}")
        count += 1
    except NotADirectoryError:
        print("not value")