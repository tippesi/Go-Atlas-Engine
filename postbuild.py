import os
import shutil

for file in os.listdir(""):
    if file.endswith(".so"):
	shutil.copy(file, os.path.join("../go", file))
