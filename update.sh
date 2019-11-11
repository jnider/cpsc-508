#!/bin/bash

# 2019-10-05
# update all of the projects from git

function update_projects()
{
	local dir=$1
	[ -d $dir ] || exit
	echo "Updating projects in $dir"
	cd $dir
	local projects=$(ls -d *)
	for project in $projects; do
		if [ -d $project ] ; then
			echo "Updating $project"
			cd $project
			git fetch && git rebase
			cd -
		fi
	done
	cd ..
}

update_projects libs
update_projects apps
update_projects unikraft

