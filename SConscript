# -*- mode: python -*-
install_root = "/home/zhouqiang/svn/tank_searcher/"
ccflags = "-I%s -I%s -std=c++11" % (install_root, install_root + 'include/')

env = Environment(CCFLAGS = ccflags)
env['install_root'] = install_root

env.SConscript('tank_searcher/SConscript', variant_dir='build', exports='env')

