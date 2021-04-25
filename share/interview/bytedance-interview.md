1. 用数组实现一个环形队列

要点：判满 `head == tail`, 判空 `head == (tail+1) % MAX_SIZE`， head 和 tail 累加环回 `head = (head+1) % MAX_SIZE`， 牺牲一个存储单位来实现判满和判空的便利性。
