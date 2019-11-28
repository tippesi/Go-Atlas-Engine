import os
import shutil
import re
from sys import platform

filetype = "(^.*)\.so(.*$)"

if (platform == "win32"):
    filetype = "(^.*)\.dll(.*$)"

for file in os.listdir("./"):
    if re.search(filetype, file):
	    copyfile = file
	    if (platform == "win32"):
		    copyfile = re.sub("\.dll", ".so", file)
	    shutil.copy(file, os.path.join("../go", copyfile))
	
os.chdir("../go")

cmd = 'go build -o App.so -buildmode=c-shared'
os.system(cmd)