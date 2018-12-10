#!/bin/bash
set -e
set -x

source vars.rc

# Build ESMF
if [ ! -f esmf.install ]; then
	cd $ESMF_DIR
	make --no-print-directory
	make --no-print-directory install 
	touch esmf.install 
	cd ..
fi

# Build MAPL
if [ ! -f mapl.install ]; then
	cd $ESMADIR 
	make --no-print-directory install 
	touch mapl.install 
	cd ..
fi

# Build FVdycore
if [ ! -f fvdycore.install ]; then
	cd $FV_DIR
	make --no-print-directory esma_install 
	touch fvdycore.install 
	cd ..
fi
