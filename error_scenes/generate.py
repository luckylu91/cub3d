finit = open('initial.cub', 'r')
init_lines = finit.readlines()

for mfield in ("R ", "NO ", "SO ", "WE ", "EA ", "S ", "F ", "C "):
	f = open("missing_" + mfield[:-1] + ".cub", "w")
	for line in filter(lambda l: not l.strip().startswith(mfield), init_lines):
		f.write(line)
	f.close()

finit.close()
