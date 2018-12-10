#!/bin/bash
set -e
set -x

source vars.rc

rm -rf pkg pkg.tar.gz
mkdir pkg
mkdir pkg/include
mkdir pkg/lib

cat install_libs.txt | while read lib
do 
	cp $lib pkg/lib
done

cat install_includes.txt | while read includes
do 
	cp $includes pkg/include
done

cd pkg
tar -czvf ../gchp-thirdparty.tar.gz .
cd ..

rm -rf pkg
