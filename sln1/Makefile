SHELL = /bin/bash -e
INC = -I inc/
CCFLAGS = -Wall 
OPTS =
CC = gcc $(CCFLAGS) $(OPTS) $(INC)
OBJ = 
AR = ar
DEBUG = 
DESIG = data
SEMESTER = fall2015
PROJ = $(shell /bin/pwd | /bin/sed 's/^.*\///')
NEXTPROJ = $(shell /bin/cat /var/public/$(SEMESTER)/$(DESIG)/projlist | /bin/grep "^$(PROJ):" | /usr/bin/cut -d':' -f2)
OTHER = $(shell /bin/cat /var/public/$(SEMESTER)/$(DESIG)/projlist | /bin/grep "^$(PROJ):" | /usr/bin/cut -d':' -f3)
NEXTPATH = /var/public/$(SEMESTER)/$(DESIG)/$(NEXTPROJ)
OTHERPATH = /var/public/$(SEMESTER)/$(DESIG)/$(OTHER)
LIBS = src
UNIT = unit
APP = app
ALL = $(LIBS) $(UNIT) $(APP)
BIN = 
default: status-begin libs units apps status-end
debug: status-begin libs-debug units-debug apps-debug status-end

libs-debug: CC += -DDEBUG -g
libs-debug: DEBUG = debug
libs-debug: libs

libs:
ifneq ($(MAKECMDGOALS),debug)
	@for i in $(LIBS); do make -sC $$i $(DEBUG); done
else
	@for i in $(LIBS); do make -C $$i $(DEBUG); done
endif

status-begin:
	@if [ `cat .updates/current` -lt `cat /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.updates/latest` ]; then echo "*********************************************************"; echo "*** NEW UPDATE AVAILABLE: Type 'make update' to apply ***"; echo "*********************************************************"; fi

status-end:
	@if [ `cat .updates/current` -lt `cat /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.updates/latest` ]; then echo "*********************************************************"; echo "*** NEW UPDATE AVAILABLE: Type 'make update' to apply ***"; echo "*********************************************************"; fi

status-quit:
	@if [ `cat .updates/current` -lt `cat /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.updates/latest` ]; then echo "*********************************************************"; echo "*** NEW UPDATE AVAILABLE: Type 'make update' to apply ***"; echo "*********************************************************"; /bin/false; fi

units-debug: CC += -DDEBUG -g
units-debug: DEBUG = debug
units-debug: units

units:
ifneq ($(MAKECMDGOALS),debug)
	@for i in $(UNIT); do make -sC $$i $(DEBUG); done
else
	@for i in $(UNIT); do make -C $$i $(DEBUG); done
endif

apps-debug: CC += -DDEBUG -g
apps-debug: DEBUG = debug
apps-debug: apps

apps:
ifneq ($(MAKECMDGOALS),debug)
	@for i in $(APP); do make -sC $$i $(DEBUG); done
else
	@for i in $(APP); do make -C $$i $(DEBUG); done
endif

check: status-begin
	@/var/public/${SEMESTER}/${DESIG}/.eval/verify-$(PROJ).sh

clean: status-begin
	@printf  "Cleaning out object code    ... "
	@for i in $(ALL); do make -sC $$i clean; done
	@rm -f errors bin/* lib/*
	@printf  "OK\n\n"

copy:
	@echo    "Commencing copy process for project $(PROJ)"
	@echo
	@echo -n "Creating project $(PROJ) directory tree           ... "
	@mkdir -p ~/src/$(DESIG)/$(PROJ) ~/src/$(DESIG)/$(PROJ)/.updates && echo "OK" || echo "error"
	@echo -n "Copying $(PROJ) files into project directory  ... "
	@cp -av /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/* ~/src/$(DESIG)/$(PROJ)/ && echo "OK" || echo "error"
	@echo -n "Synchronizing $(PROJ) project revision level      ... "
	@cp -f /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.updates/current ~/src/$(DESIG)/$(PROJ)/.updates/ && echo "OK" || echo "error"
	@echo -n "Establishing sane file permissions for $(PROJ)    ... "
	@chmod -R u=rwX,go= ~/src/$(DESIG)/$(PROJ) && echo "OK" || echo "error"
	@echo
	@echo "Copy Complete! You may now switch to the ~/src/$(DESIG)/$(PROJ) directory"
	@echo
	@echo "[${USER}] obtaining project '$(PROJ)' (revision `cat /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.updates/latest`) in `pwd` (`date +\"%Y%m%d%H%M\"`)" >> /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.updates/log

save: clean
	@echo
	@echo    "Project backup process commencing"
	@echo
	@echo -n "Taking snapshot of current project ($(PROJ))      ... "
	@(cd ..; tar cf $(PROJ)-`date +%Y%m%d-%H`.tar $(PROJ) && echo "OK" || echo "error")
	@echo -n "Compressing snapshot of $(PROJ) project archive   ... "
	@gzip -f -9 ../$(PROJ)-*.tar && echo "OK" || echo "error"
	@echo -n "Setting secure permissions on $(PROJ) archive     ... "
	@chmod 600 ../$(PROJ)-*.gz && echo "OK" || echo "error"
	@echo
	@echo    "Project backup process complete"
	@echo

submit: save
	@submit $(DESIG) $(PROJ) `/bin/ls -1 ../$(PROJ)*gz | tail -1`
	@echo "[${USER}] submitting project '$(PROJ)' in `pwd` (`date +\"%Y%m%d%H%M\"`)" >> /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.updates/log

use-test-reference: clean
	@if [ -f "/var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.datastore/refimp.sh" ]; then sh /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.datastore/refimp.sh `pwd` "$(SEMESTER)/$(DESIG)/$(PROJ)"; fi
	@echo "NODE reference implementation in place, run 'make' to build everything."

use-your-own-code:
	@if [ -f "/var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.datastore/locimp.sh" ]; then sh /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.datastore/locimp.sh `pwd` "$(SEMESTER)/$(DESIG)/$(PROJ)"; fi
	@echo "Local node implementation restored, run 'make clean; make' to build everything."

update:
	@for((i=`cat .updates/current`+1; i<=`cat /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.updates/latest`; i++)); do sh /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.updates/$$i $(SEMESTER) $(DESIG) $(PROJ); echo "[${USER}] applying revision $$i of '$(PROJ)' in `pwd` (`date +\"%Y%m%d%H%M\"`)" >> /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.updates/log; done
	@chmod -R u=rwX,go= .
	@echo "Updated from revision `cat .updates/current` to revision `cat /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.updates/latest`"
	@cat /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.updates/latest > .updates/current

reupdate:
	@for((i=`cat .updates/current`; i<=`cat .updates/current`; i++)); do sh /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.updates/$$i $(SEMESTER) $(DESIG) $(PROJ); echo "[${USER}] re-applying revision $$i of '$(PROJ)' in `pwd` (`date +\"%Y%m%d%H%M\"`)" >> /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.updates/log; done
	@chmod -R u=rwX,go= .
	@echo "Re-applying revision `cat .updates/current`"

reupdate-all:
	@for((i=1; i<=`cat .updates/current`; i++)); do sh /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.updates/$$i $(SEMESTER) $(DESIG) $(PROJ); echo "[${USER}] re-applying revision $$i of '$(PROJ)' in `pwd` (`date +\"%Y%m%d%H%M\"`)" >> /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.updates/log; done
	@chmod -R u=rwX,go= .
	@echo "Re-applied updates from revision 1 to revision `cat .updates/current`"

upgrade-$(NEXTPROJ): status-quit clean save
	@echo    "Commencing upgrade process from $(PROJ) to $(NEXTPROJ)"
	@echo
	@echo -n "Creating project $(NEXTPROJ) directory tree           ... "
	@mkdir -p ../$(NEXTPROJ) ../$(NEXTPROJ)/.updates && echo "OK" || echo "error"
	@echo -n "Copying your code to $(NEXTPROJ) project directory    ... "
	@cp -a * ../$(NEXTPROJ) && echo "OK" || echo "error"
	@echo -n "Copying new $(NEXTPROJ) files into project directory  ... "
	@cp -a /var/public/$(SEMESTER)/$(DESIG)/$(NEXTPROJ)/* ../$(NEXTPROJ)/ && echo "OK" || echo "error"
	@echo -n "Synchronizing $(NEXTPROJ) project revision level      ... "
	@cp -f /var/public/$(SEMESTER)/$(DESIG)/$(NEXTPROJ)/.updates/current ../$(NEXTPROJ)/.updates/ && echo "OK" || echo "error"
	@if [ -f "/var/public/$(SEMESTER)/$(DESIG)/$(NEXTPROJ)/.updates/prune" ]; then echo -n "Pruning obsoleted files from $(NEXTPROJ) project tree ... "; sh /var/public/$(SEMESTER)/$(DESIG)/$(NEXTPROJ)/.updates/prune ../$(NEXTPROJ) && echo "OK" || echo "error"; fi
	@echo -n "Establishing sane file permissions for $(NEXTPROJ)    ... "
	@chmod -R u=rwX,go= ../$(NEXTPROJ) && echo "OK" || echo "error"
	@echo
	@echo "Upgrade Complete! You may now switch to the ../$(NEXTPROJ) directory"
	@echo
	@echo "[${USER}] upgrading to project '$(NEXTPROJ)' (revision `cat /var/public/$(SEMESTER)/$(DESIG)/$(NEXTPROJ)/.updates/latest`) in `pwd` (`date +\"%Y%m%d%H%M\"`)" >> /var/public/$(SEMESTER)/$(DESIG)/$(NEXTPROJ)/.updates/log

get-$(OTHER): status-quit clean save
	@make -C /var/public/$(SEMESTER)/$(DESIG)/$(OTHER) copy

help: status-begin
	@if [ "`echo $(PROJ) | cut -c3`" = "s" ]; then echo "****************[ Data Structures Stack Implementation ]****************"; elif [ "`echo $(PROJ) | cut -c3`" = "q" ]; then echo "****************[ Data Structures Queue Implementation ]****************"; elif [ "`echo $(PROJ) | cut -c3`" = "l" ]; then echo "****************[ Data Structures List Implementation ]*****************"; elif [ "`echo $(PROJ) | cut -c3`" = "n" ]; then echo "****************[ Data Structures Node Implementation ]*****************"; elif [ "`echo $(PROJ) | cut -c3`" = "t" ]; then echo "****************[ Data Structures Tree Implementation ]*****************"; else echo "****************[ Data Structures Code Implementation ]*****************"; fi
	@echo "** make                     - build everything (libs, units, apps)    **"
	@echo "** make debug               - build everything with debug symbols     **"
	@echo "** make check               - check implementation for validity       **"
	@echo "**                                                                    **"
	@echo "** make libs                - build all supporting libraries          **"
	@echo "** make libs-debug          - build all libraries with debug symbols  **"
	@if [ -d "app/" ]; then echo "** make apps                - build unit tests                        **"; echo "** make apps-debug          - build unit tests with debugging symbols **"; fi
	@echo "** make units               - build unit tests                        **"
	@echo "** make units-debug         - build unit tests with debugging symbols **"
	@if [ -f "/var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.datastore/refimp.sh" ]; then echo "**                                                                    **"; echo "** make use-test-reference  - use working implementation object files **"; echo "** make use-your-own-code   - use your own implementation code        **"; fi
	@echo "**                                                                    **"
	@echo "** make save                - create a backup archive                 **"
	@echo "** make submit              - submit assignment (based on dirname)    **"
	@echo "**                                                                    **"
	@echo "** make update              - check for and apply updates             **"
	@echo "** make reupdate            - re-apply last revision                  **"
	@echo "** make reupdate-all        - re-apply all revisions                  **"
	@echo "**                                                                    **"
	@if [ -r $(NEXTPATH) ]; then /usr/bin/printf "** %-24s " "make upgrade-$(NEXTPROJ)"; /usr/bin/printf "- %-39s **\n" "upgrade to next project ($(NEXTPROJ))"; fi
	@if [ ! -z "$(OTHER)" ] && [ -r $(OTHERPATH) ]; then /usr/bin/printf "** %-24s " "make get-$(OTHER)"; /usr/bin/printf "- %-39s **\n" "obtain new project ($(OTHER))"; echo "**                                                                    **"; fi
	@echo "** make clean               - clean; remove all objects/compiled code **"
	@echo "** make help                - this information                        **"
	@echo "************************************************************************"
