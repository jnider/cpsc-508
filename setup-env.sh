#!/bin/bash

# J.Nider 2019-10-02
#
# Set up the Unikraft build environment

repo_url_unikraft="http://xenbits.xen.org/git-http/unikraft/unikraft.git"
repo_url_newlib="http://xenbits.xen.org/git-http/unikraft/libs/newlib.git"
repo_url_lwip="http://xenbits.xen.org/git-http/unikraft/libs/lwip.git"
repo_url_helloworld="https://xenbits.xen.org/git-http/unikraft/apps/helloworld.git"
repo_url_httpreply="https://xenbits.xen.org/git-http/unikraft/apps/httpreply.git"
repo_url_nginx="https://github.com/unikraft/lib-nginx.git"
repo_url_intel="https://github.com/unikraft/lib-intel-intrinsics.git"
repo_url_uuid="https://github.com/unikraft/lib-libuuid.git"
repo_url_micropython="https://github.com/unikraft/micropython.git"
repo_url_openssl="https://github.com/unikraft/openssl.git"
repo_url_pthread="https://github.com/unikraft/pthread-embedded.git"
repo_url_python3="https://github.com/unikraft/python3.git"
repo_url_zlib="https://github.com/unikraft/lib-zlib.git"

function git_clone()
{
	local target_dir=$1
	local url=$2
	local branch=$3

	if [ -d $target_dir ]; then
		echo "directory $target_dir already exists - skipping"
	else
		git clone $url $target_dir
 		if [ $? != 0 ]; then
			echo "Cloning $target_dir failed"
			exit -1
		fi
	fi
	cd $target_dir
	git checkout $branch
	cd -
}

mkdir -p libs apps
# the core unikraft libraries
git_clone "unikraft" $repo_url_unikraft "staging"
# the supplementary libraries
git_clone "libs/intel-intrinsics" $repo_url_intel "staging"
git_clone "libs/libuuid" $repo_url_uuid "staging"
git_clone "libs/lwip" $repo_url_lwip "staging"
git_clone "libs/micropython" $repo_url_micropython "staging"
git_clone "libs/newlib" $repo_url_newlib "staging"
git_clone "libs/nginx" $repo_url_nginx "staging"
git_clone "libs/openssl" $repo_url_openssl "staging"
git_clone "libs/pthread-embedded" $repo_url_pthread "staging"
git_clone "libs/python3" $repo_url_python3 "staging"
git_clone "libs/zlib" $repo_url_zlib "staging"

# the apps
git_clone "apps/helloworld" $repo_url_helloworld "staging"
git_clone "apps/httpreply" $repo_url_httpreply "master"

echo "sudo apt install libncurses-dev flex unzip python3-venv"
echo "Unikraft environment is ready"
