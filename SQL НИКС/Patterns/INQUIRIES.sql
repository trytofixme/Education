
SELECT Client_Info.Client_id, Name, Surname 
FROM Client_Info
INNER JOIN Journey_Client_Info ON Journey_Client_Info.Client_id = Client_Info.Client_id
INNER JOIN Journey ON Journey_Client_Info.Journey_id = Journey.Journey_id
INNER JOIN Journey_Hotel ON Journey_Hotel.Journey_id = Journey.Journey_id
INNER JOIN Hotel ON Journey_Hotel.Hotel_id = Hotel.Hotel_id
WHERE DATEDIFF(DAY, [Start_Date], End_Date) >=28 AND Hotel.City_id IN (SELECT 
--������� ���� �������� ������� �������� � ����� � ������� ����� ��� 28 ����

SELECT TOP(1) WITH TIES Journey.Employee_id,  Employee.Employee_Name, COUNT(Journey_id) AS Journeys 
FROM Journey
INNER JOIN Employee ON Journey.Employee_id = Employee.Employee_id
WHERE ([Start_Date] >='01.01.2018')
GROUP BY Journey.Employee_id, Employee.Employee_Name
ORDER BY Journeys DESC
--������� ���������� ����������� ������ ����� ������� � 01.01.2018


SELECT TOP(1) WITH TIES Client_Info.Client_id, Client_Info.Name, COUNT(Journey.Journey_id) AS Journeys 
FROM Client_Info
INNER JOIN Journey_Client_Info ON Client_Info.Client_id = Journey_Client_Info.Client_id
INNER JOIN Journey ON Journey_Client_Info.Journey_id = Journey.Journey_id
INNER JOIN Journey_Hotel ON Journey.Journey_id = Journey_Hotel.Journey_id
INNER JOIN Hotel ON Journey_Hotel.Hotel_id = Hotel.Hotel_id
INNER JOIN City ON Hotel.City_id = City.City_id
WHERE (City.City_id = 4)
GROUP BY Client_Info.Client_id, Client_Info.Name
ORDER BY Journeys DESC
--������� ��� �������� ������� �������� ������ ����� ��� ������ �� ��� �����


SELECT TOP(1) WITH TIES Client_Info.Client_id, Client_Info.Name, Client_Info.Surname, SUM(Ticket.Cost) AS [Ticket Cost], SUM(Hotel.Cost_For_Person) AS [Hotel Cost], SUM(Ticket.Cost + Hotel.Cost_For_Person) AS SuperSum 
FROM Client_Info
INNER JOIN Ticket ON Client_Info.Client_id = Ticket.Client_id
INNER JOIN  Journey_Client_Info ON Client_Info.Client_id = Journey_Client_Info.Client_id AND Journey_Client_Info.Journey_id = Ticket.Journey_id
INNER JOIN Journey ON Journey_Client_Info.Journey_id = Journey.Journey_id
INNER JOIN Journey_Hotel ON Journey.Journey_id = Journey_Hotel.Journey_id
INNER JOIN Hotel ON Journey_Hotel.Hotel_id = Hotel.Hotel_id  AND Hotel.City_id = Ticket.Destination_id
GROUP BY Client_Info.Client_id, Client_Info.Name, Client_Info.Surname
ORDER BY SuperSum DESC
--������� ������� ������� �������� ������ ���� �������� �� ����� � �������

SELECT * 
SELECT  Sea.[Description] AS [SEA], Hotel.[Description] AS [HOTEL] FROM Journey_Client_Info
INNER JOIN Journey ON Journey.Journey_id = Journey_Client_Info.Journey_id
INNER JOIN Journey_Hotel ON Journey_Hotel.Journey_id = Journey.Journey_id
INNER JOIN Hotel On Journey_Hotel.Hotel_id = Hotel.Hotel_id
INNER JOIN  Sea ON Hotel.Sea_id = Sea.Sea_id
WHERE Client_id = 5 AND ([Start_Date] >= '01.01.2018') AND (End_Date < '01.01.2019')


--������� ���� � �������� ������, ������� ������� '�����������' � ������� ����.


SELECT Excursion.Excursion_Company_id,[Description],  SUM(Cost) AS [Money Summary] FROM Excursion
INNER JOIN Excursion_Company on Excursion.Excursion_Company_id = Excursion_Company.Excursion_Company_id
WHERE [Start_Date] > '31.12.2017' AND [Start_Date] < '01.01.2019' 
GROUP BY Excursion.Excursion_Company_id, [Description]
HAVING SUM(Cost) > 500 
--������� �� ������������� ��������, ������� ������� ������ ����� ��������� �� 2018 ��� �� ����� ����� 500

SELECT Journey_Client_info.Client_id,  SUM(DATEDIFF(DAY, [Start_Date], End_Date)) AS [Days], COUNT(Journey_Client_Info.Client_id) AS [Amount Of Places] 
FROM Journey_Client_Info
INNER JOIN Journey on Journey_Client_info.Journey_id = Journey.Journey_id
WHERE [Start_Date] >= '01.01.2018' AND [Start_Date] < '01.01.2019'
GROUP BY Journey_Client_info.Client_id
--������� ���������� ���� ������ � ���������� ���� ������ � ������� ���� ��� ������� ������� �����.