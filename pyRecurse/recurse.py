
def recurse(first, i):
    if (first.__len__()==i):
        return 0
    
    return first[i] + recurse(first, i+1)
    
def main():
    first = range(40)
    print "list: ", first
    solution = recurse(first, 0)
    print "solution: ", solution
    
if __name__ == "__main__":main()