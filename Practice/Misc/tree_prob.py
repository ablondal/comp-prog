from sys import stdin

class Main:

    def __init__(self):
        self.n = int(input())
        self.good_nodes = set(range(1, self.n+1))

        self.adj_list = {}
        for i in range(1, self.n + 1):
            self.adj_list[i] = []

        self.colors = {}
        for i in range(1, self.n + 1):
            self.colors[i] = {}

        # inp = os.read(0, 1<<20)
        # ints = list(map(int, inp.split()))

        for i in range(self.n - 1):
            a, b, c = map(int, stdin.readline().split())
            self.adj_list[a].append(b)
            self.adj_list[b].append(a)
            self.add_color(a, b, c)
            self.add_color(b, a, c)

        self.visited = set()
        # print(self.adj_list)
        # print(self.colors)

    def add_color(self, a, b, c):
        if c not in self.colors[a]:
            self.colors[a][c] = [b]
        else:
            self.colors[a][c].append(b)

    def dfs(self, current, start):
        previous = current
        stack = [(start, previous)]
        while len(stack) != 0:
            current_node, parent = stack.pop()
            if (current_node, parent) in self.visited:
                continue
            # print(current_node, "<-",  parent)
            self.visited.add((current_node, parent))
            if current_node in self.good_nodes:
                self.good_nodes.remove(current_node)
            for adj_node in self.adj_list[current_node]:
                if adj_node != parent:
                    stack.append((adj_node, current_node))

    def run(self):
        for current_node, value1 in self.colors.items():
            if len(self.good_nodes) == 0:
                break
            for value2 in value1.values():
                if len(value2) > 1:
                    for node in value2:
                        if ((node, current_node) not in self.visited):
                            self.dfs(current_node, node)
        print(len(self.good_nodes))
        for x in self.good_nodes:
            print(x)


main = Main()
main.run()