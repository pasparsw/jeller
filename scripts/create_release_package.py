import os
import shutil
import platform

SYSTEM: str = 'win' if 'Windows' in platform.platform() else 'linux'
SCRIPT_DIR: str = os.path.dirname(os.path.realpath(__file__))
REPO_DIR: str = os.path.join(SCRIPT_DIR, '..')
BUILD_DIR: str = os.path.join(REPO_DIR, 'build')
PUBLIC_INCLUDE_DIR: str = os.path.join(REPO_DIR, 'include', 'jeller')
RELEASE_PACKAGE_DIR: str = os.path.join(REPO_DIR, f'jeller_{SYSTEM}')

if os.path.exists(RELEASE_PACKAGE_DIR):
    shutil.rmtree(RELEASE_PACKAGE_DIR)

os.mkdir(RELEASE_PACKAGE_DIR)
os.mkdir(os.path.join(RELEASE_PACKAGE_DIR, 'Debug'))
os.mkdir(os.path.join(RELEASE_PACKAGE_DIR, 'Release'))

shutil.copytree(PUBLIC_INCLUDE_DIR, os.path.join(RELEASE_PACKAGE_DIR, 'include', 'jeller'))

if 'Windows' in platform.platform():
    shutil.copy2(os.path.join(BUILD_DIR, 'Debug', 'Jeller.dll'), os.path.join(RELEASE_PACKAGE_DIR, 'Debug'))
    shutil.copy2(os.path.join(BUILD_DIR, 'Debug', 'Jeller.lib'), os.path.join(RELEASE_PACKAGE_DIR, 'Debug'))
    shutil.copy2(os.path.join(BUILD_DIR, 'Debug', 'Jeller.pdb'), os.path.join(RELEASE_PACKAGE_DIR, 'Debug'))
    shutil.copy2(os.path.join(BUILD_DIR, 'Release', 'Jeller.dll'), os.path.join(RELEASE_PACKAGE_DIR, 'Release'))
    shutil.copy2(os.path.join(BUILD_DIR, 'Release', 'Jeller.lib'), os.path.join(RELEASE_PACKAGE_DIR, 'Release'))
elif 'Linux' in platform.platform():
    shutil.copy2(os.path.join(BUILD_DIR, 'Debug', 'libJeller.so'), os.path.join(RELEASE_PACKAGE_DIR, 'Debug'))
    shutil.copy2(os.path.join(BUILD_DIR, 'Release', 'libJeller.so'), os.path.join(RELEASE_PACKAGE_DIR, 'Release'))
