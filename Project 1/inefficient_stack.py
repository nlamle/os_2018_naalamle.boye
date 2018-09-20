#inefficient_stack.py
#Naa Lamle Boye
#15th September, 2017.

class InefficientStack:
    def __init__(self):
        self.things = []

    def isEmpty(self):
        return self.things == []

    def bottomPush(self, thing):
        self.things.insert(0, thing)

    def bottomPop(self):
        self.things.remove(self.things[0])

    def bottomPeek(self):
        return self.things[0]

    def size(self):
        return len(self.things)

    def listThings(self):
        for a in self.things:
            print (a)

    def __str__(self):
        return str(self.things)


def main():
    iS = InefficientStack()
    iS.isEmpty()
    iS.bottomPush(5)
    iS.bottomPush(3)
    iS.bottomPush(45)
    iS.bottomPop()
##    iS.bottomPop()
##    print(iS.size())
    iS.listThings()
    print(iS)
main()
