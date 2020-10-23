UPDATE City
SET Country_Name = 'Russia'
WHERE City_id IN (SELECT City_id
FROM City
WHERE City.City_Name = 'New York')
--����� �������� ������ ������ "NEW YORK" �� "RUSSIA"

UPDATE Client_Info
SET Email = 'dogcat@phystech.edu'
WHERE Client_id IN (SELECT Client_id
FROM Client_Info
WHERE Client_Info.Name = 'Gumbo' AND Client_Info.Surname = 'Dumbo')
--����� ������ ����������� ����� ������ �� ��������

UPDATE Client_Info
SET Client_id = 2
WHERE Client_id IN (SELECT Client_id
FROM Client_Info
WHERE Client_Info.Surname = 'Molozhavenko' AND Client_Info.Name = 'Alexander')

UPDATE International_Passport
SET Int_Passnumber = '22831F'
WHERE Client_id = 5 OR Client_id = 6
Select *
FROM International_Passport
--������� ������������ ����������� ����������� (IDENTITY � PRIMARY KEY)


UPDATE Hotel
SET Cost_For_Person = Cost_For_Person + (CASE WHEN Amount_Of_Stars = '5' THEN (0.5*Cost_For_Person) ELSE (0.1*Cost_For_Person) END)
WHERE City_id IN (SELECT City_id
FROM City
WHERE City.Country_Name = 'Russia')
--� ���� �������������� ������ � ������ ������� ���� �� 50% � ��������� �� 10%


DELETE FROM International_Passport
WHERE Client_id IN (SELECT Client_id
FROM Client_Info INNER JOIN City on Client_Info.Homecity_id = City.City_id
WHERE City_Name = 'Moscow')
--������� ��� ������.�������� �������� �� ������ 


DELETE FROM Client_Info
WHERE Client_id > 0
--��������� ����������� ����������� (������� ������� ���� �� PK)

DELETE FROM Phone_Number
WHERE Hotel_id IS  NULL 
--������� ������ ��������� ���� �������� � ���� ������������� ��������