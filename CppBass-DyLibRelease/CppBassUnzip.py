import zipfile as fl
import os
import sys
def Main():
    print("Windows Version: " + sys.winver)
    os.mkdir(path=os.getcwd() + "\\CppBassRel")
    with fl.ZipFile(file="CppBassDyLibEdition_Rel.zip", mode="r") as zip:
        zip.extractall(path=os.getcwd() + "\\CppBassRel")
        os.system("start {}".format(os.getcwd() + "\\CppBassRel\\CppBass-DyLib.exe"))
    exit(3004)

if __name__ == "__main__":
    Main()