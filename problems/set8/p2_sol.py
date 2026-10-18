class Bbread:
    taste = '밀가루'

    def eat(self):
        print(self.taste, '맛이 나요!')


redBean = Bbread()
choux = Bbread()

redBean.taste = '팥'
choux.taste = '슈크림'

redBean.eat()
choux.eat()
