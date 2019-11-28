import os
	
os.chdir("../go")

cmd = 'go build -o App.so -buildmode=c-shared'
os.system(cmd)