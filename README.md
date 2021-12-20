# ADDLICENSE
quick creation of license files.

## BUILD
### ENVIRONMENT
cmake > 3.5
gcc > 7.0
```bash
git clone https://github.com/kamino-space/AddLicense.git
cd AddLicense
mkdir build
cd build
cmake ..
# for linux
make
# for windows
nmake
# or
g++ AddLicense.cpp -o addlic
```
## ADD TO PATH
### windows
[windows10设置环境变量PATH](https://jingyan.baidu.com/article/8ebacdf02d3c2949f65cd5d0.html)
### linux
[Linux添加$PATH环境变量](https://jingyan.baidu.com/article/fdbd4277c118ccb89e3f4817.html)

## USAGE
```bash
usage: addlic [licenses] or [options]
demo:   addlic mit
        addlic ls
supported licenses:
        mit     MIT License
        gpl     GNU General Public License v3.0
        agpl    GNU Affero General Public License v3.0
        lgpl    GNU Lesser General Public License v3.0
        moz     Mozilla Public License 2.0
        apache  Apache License 2.0
        unlic   The Unlicense
supported options:
        help    show usage message
        ls      list all licenses
        select  follow the information to choose
        version show version
        web     enter choosealicense website
```

# LICENSE
MIT
