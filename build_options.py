# -*- mode: python -*- #
####################################################################
# You set build options for "ascons" in this file.                 #
# Invoke "scons -h" to see all available options.                  #
#                                                                  #
# ascons' wiki:                                                    #
# http://grd.alibaba-inc.com/projects/heavenasks/wiki/ascons_usage #
####################################################################

install_root = ''
install_prefix = '/usr/local'
depend_prefix = [install_root + install_prefix]
#paths of dependent xxx files which are not in %depend_prefix%/xxx 
#can be given by the follow options. (xxx = include or lib)
#depend_includedir = []
depend_libdir = ['/usr/ali/java/jre/lib/amd64/server/']
#depend_bindir = []

heapchecktype = 'tcmalloc'
mode = 'release'
enable_strip = True
librarytype = 'shared'
