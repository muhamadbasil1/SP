import psutil
import sys

def main():
	
	p = psutil.Process(int(sys.argv[1]))
	
	print "Process ID: %s" % sys.argv[1]
	print "Process Name: " + p.name()
	print "Process Status: "+ p.status()
	print "Process Parent ID: %d" % p.ppid()
	print "Process Parent Name: %s" % p.parent().name()
	print "Process Creation Time: %f" % p.create_time()
	print "File opened by process info: "
	print p.open_files()
	print "Memory Info: "
	print p.memory_info()
	





main()	
