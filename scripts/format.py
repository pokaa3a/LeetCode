import glob
import os

# Ex. 
# ../problems/940. Distinct Subsequences II.cc -> ../problems/0940_Distinct_Subsequences_II.cpp

def formulate(cpp_file):
    filename = os.path.basename(cpp_file)

    parts = filename.split()

    parts[0] = '{0:04d}'.format(int(parts[0][:-1]))
    parts[-1] = os.path.splitext(parts)[0]

    new_name = ''
    for x in parts:
        new_name += x + '_'

    new_name = new_name[:-1] + '.cpp'
    
    src_name = cpp_file
    dst_name = cpp_file.replace(filename, new_name)

    print src_name + ' => ' + dst_name
    os.rename(src_name, dst_name)

def main():
    scripts_dir = os.path.dirname(os.path.realpath(__file__))
    problems_dir = os.path.join(scripts_dir, '..', 'problems')

    cpp_files = glob.glob(os.path.join(problems_dir, '*.cc'))
    for cpp in cpp_files:
        formulate(cpp)

if __name__ == '__main__':
    main()
