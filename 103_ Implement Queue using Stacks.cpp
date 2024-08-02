class MyQueue:
    def __init__(self):
        self.st1 = []

    def push(self, x):
        temp = []
        while self.st1:
            temp.append(self.st1.pop())
        self.st1.append(x)
        while temp:
            self.st1.append(temp.pop())

    def pop(self):
        front = self.st1[-1]
        self.st1.pop()
        return front

    def peek(self):
        return self.st1[-1]

    def empty(self):
        return not self.st1
