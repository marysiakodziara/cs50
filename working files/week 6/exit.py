from sys import argv

if len(argv) != 2:
    print("Missing command-line argument")
    sys.exit(1)

print(f"hello, {argv[1]}")
sys.exit(0)