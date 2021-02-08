from queue import Queue
#Белые - не посещенные, Серые - посещенные, Черные - уже зафиксированные
result, data, colour, destination, ancestors ={}, [], {}, {}, {} 
# Словарь с вершина - результат BFS, массив вершин, цвет вершин, расстояние между вершинами, предки
mass, n = [[3,0],[3,1],[3,2],[3,4],[5,4]], 6 # Данныe
infty = 9223372036854775807
if n > 1:
    for el in mass:
        for u in el:
            if u not in data:
                data.append(u)
    for x in data:
        if x in result.keys():
            next
        for el in data:
            colour[el] = 'Белый' #Пометим все ребра белыми
            ancestors[el] = None
            destination[el] = infty
        start_pos = x
        colour[start_pos] = 'Серый'
        destination[start_pos] = 0


        q = Queue() # Здесь храним серые вершины
        q.put(start_pos)
        while not q.empty():
            get = q.get() #Извлекаем из очереди
            for el in mass:
                for u in el:
                    if u != get and get in el and colour[u] == 'Белый':
                        #Если вершина в (u, v), u не совпадает с v, u еще не открыта
                        q.put(u) #Кладем в очередь
                        colour[u] = 'Серый' #Помечаем как открытую
                        destination[u] = destination[get] + 1 
            colour[get] = 'Черный' #Закрываем вершину
        result[start_pos] = max(destination.values())
        # Добавляем вершину - максимальную ширину обхода дерева
    print([x for x, y in result.items() if y == min(result.values())])
else:                           
    print(0)
    
