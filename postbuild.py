import os
import shutil
import re
from sys import platform

filetype = "(^.*)\.so(.*$)"

if (platform == "win32"):
    filetype = "(^.*)\.dll(.*$)"
if (platform == "darwin"):
    filetype = "(^.*)\.dylib(.*$)"
for file in os.listdir("./"):
    if re.search(filetype, file):
        copyfile = file
        if (platform == "win32"):
            copyfile = re.sub("\.dll", ".so", file)
        if (platform == "darwin"):
            copyfile = re.sub("\.dylib", ".so", file)
        shutil.copy(file, os.path.join("../go", copyfile))