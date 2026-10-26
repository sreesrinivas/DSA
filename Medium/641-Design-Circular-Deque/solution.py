class MyCircularDeque:

    def __init__(self, k: int):
        self.capacity = k
        self.count = 0
        self.front = k - 1
        self.rear = 0
        self.buffer = [0] * k

    def insertFront(self, value: int) -> bool:
        if self.isFull():
            return False
        self.buffer[self.front] = value
        self.front = (self.front - 1 + self.capacity) % self.capacity
        self.count += 1
        return True

    def insertLast(self, value: int) -> bool:
        if self.isFull():
            return False
        self.buffer[self.rear] = value
        self.rear = (self.rear + 1) % self.capacity
        self.count += 1
        return True

    def deleteFront(self) -> bool:
        if self.isEmpty():
            return False
        self.front = (self.front + 1) % self.capacity
        self.count -= 1
        return True

    def deleteLast(self) -> bool:
        if self.isEmpty():
            return False
        self.rear = (self.rear - 1 + self.capacity) % self.capacity
        self.count -= 1
        return True

    def getFront(self) -> int:
        return self.buffer[(self.front + 1) % self.capacity] if not self.isEmpty() else -1

    def getRear(self) -> int:
        return self.buffer[(self.rear - 1 + self.capacity) % self.capacity] if not self.isEmpty() else -1

    def isEmpty(self) -> bool:
        return not self.count

    def isFull(self) -> bool:
        return self.count == self.capacity


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()
