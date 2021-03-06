USE TutorialDB
CREATE TABLE City
(
	City_id INT NOT NULL CONSTRAINT PK_CITY PRIMARY KEY IDENTITY,
	City_Name NVARCHAR(30) NOT NULL,
	Country_Name NVARCHAR(30) NOT NULL
)

CREATE TABLE Client_Info
(
	Client_id INT NOT NULL CONSTRAINT PK_CLIENT_INFO PRIMARY KEY IDENTITY,
	Name NVARCHAR(30) NOT NULL,
	Surname NVARCHAR(30) NOT NULL,
	Email NVARCHAR(80),
	Homecity_id INT NOT NULL
	CONSTRAINT FK_CLIENT_INFO_TO_CITY FOREIGN KEY (Homecity_id) REFERENCES City (City_id)
)
CREATE TABLE Employee
(
	Employee_id INT NOT NULL CONSTRAINT PK_EMPLOYEE PRIMARY KEY IDENTITY,
	Employee_Name NVARCHAR(30) NOT NULL,
	Employee_Surname NVARCHAR(30) NOT NULL,
	Employee_Phonenumber NVARCHAR(30) NOT NULL,
	City_id INT NOT NULL,
	CONSTRAINT FK_EMPLOYEE_TO_CITY FOREIGN KEY (City_id) REFERENCES City (City_id)
)

CREATE TABLE International_Passport
(
	Int_Passnumber NVARCHAR(30) NOT NULL CONSTRAINT PK_INTERNATIONAL_PASSPORT PRIMARY KEY,
	Client_id INT NOT NULL,
	CONSTRAINT FK_INTERNATIONAL_PASSPORT_TO_CLIENT_INFO FOREIGN KEY (Client_id) REFERENCES Client_Info (Client_id) ON DELETE CASCADE
)
CREATE TABLE Transport
(
	Transport_id INT NOT NULL CONSTRAINT PK_TRANSPORT PRIMARY KEY IDENTITY,
	Description NVARCHAR(300) NOT NULL
)

CREATE TABLE Excursion_Company
(
	Excursion_Company_id INT NOT NULL CONSTRAINT PK_EXCURSION_COMPANY PRIMARY KEY IDENTITY,
	Description NVARCHAR(300) NOT NULL,
	City_id INT NULL,
	CONSTRAINT FK_EXCURSION_COMPANY_TO_CITY FOREIGN KEY (City_id) REFERENCES City (City_id)
)
CREATE TABLE Journey
(
	Journey_id INT NOT NULL CONSTRAINT PK_JOURNEY PRIMARY KEY IDENTITY,
	Start_Date DATE NOT NULL,
	End_Date DATE NOT NULL,
	Employee_id INT NOT NULL,
	CONSTRAINT FK_JOURNEY_TO_EMPLOYEE FOREIGN KEY (Employee_id) REFERENCES Employee (Employee_id)
)
CREATE TABLE Sea
(
	Sea_id INT NOT NULL CONSTRAINT PK_SEA PRIMARY KEY IDENTITY,
	Description NVARCHAR(300) NOT NULL
)
CREATE TABLE Hotel
(
	Hotel_id INT NOT NULL CONSTRAINT PK_HOTEL PRIMARY KEY,
	Description NVARCHAR(30) NOT NULL,
	City_id INT NULL,
	Amount_Of_Stars NVARCHAR(1),
	Sea_id INT NOT NULL,
	Cost_For_Person MONEY NOT NULL,
	Adress NVARCHAR(300) NOT NULL,
	CONSTRAINT FK_HOTEL_TO_CITY FOREIGN KEY (City_id) REFERENCES City (City_id),
	CONSTRAINT FK_HOTEL_TO_SEA FOREIGN KEY (Sea_id) REFERENCES Sea (Sea_id)
)
CREATE TABLE Ticket
(
	Ticket_id INT NOT NULL CONSTRAINT PK_TICKET PRIMARY KEY IDENTITY,
	Client_id INT NOT NULL,
	Purschase_Date DATE NOT NULL,
	Transport_id INT NOT NULL,
	Cost MONEY NOT NULL,
	Journey_id INT NOT NULL,
	Destination_id INT NULL,
	Depart_Date DATE NOT NULL,
	Arrive_Date DATE NOT NULL,
	CONSTRAINT FK_TICKET_TO_CLIENT_INFO FOREIGN KEY (Client_id) REFERENCES Client_Info (Client_id) ON DELETE CASCADE,
	CONSTRAINT FK_TICKET_TO_TRANSPORT FOREIGN KEY (Transport_id) REFERENCES Transport (Transport_id),
	CONSTRAINT FK_TICKET_TO_JOURNEY FOREIGN KEY (Journey_id) REFERENCES Journey (Journey_id),
	CONSTRAINT FK_TICKET_TO_CITY FOREIGN KEY (Destination_id) REFERENCES City (City_id),
)
CREATE TABLE Excursion
(
	Excursion_id INT NOT NULL CONSTRAINT PK_EXCURSION PRIMARY KEY IDENTITY,
	Journey_id INT NOT NULL,
	Excursion_Company_id INT NOT NULL,
	Excursion_Description NVARCHAR(3000) NOT NULL,
	Start_Date DATE NOT NULL,
	End_Date DATE NOT NULL,
	Transport_id INT NOT NULL,
	Cost MONEY NOT NULL,
	CONSTRAINT FK_EXCURSION_TO_JOURNEY FOREIGN KEY (Journey_id) REFERENCES Journey (Journey_id) ON DELETE CASCADE,
	CONSTRAINT FK_EXCURSION_TO_EXCURSION_COMPANY FOREIGN KEY (Excursion_Company_id) REFERENCES Excursion_Company (Excursion_Company_id),
	CONSTRAINT FK_EXCURSION_TO_TRANSPORT FOREIGN KEY (Transport_id) REFERENCES Transport (Transport_id),
)
CREATE TABLE Hotel_Excursion
(
	Hotel_id INT NOT NULL,
	Excursion_id INT NOT NULL,
	CONSTRAINT PK_HOTEL_EXCURSION PRIMARY KEY (Hotel_id, Excursion_id),
	CONSTRAINT FK_HOTEL_EXCURSION_TO_HOTEL FOREIGN KEY (Hotel_id) REFERENCES Hotel (Hotel_id) ,
	CONSTRAINT FK_HOTEL_EXCURSION_TO_EXCURSION FOREIGN KEY (Excursion_id) REFERENCES Excursion (Excursion_id) ON DELETE CASCADE

)
CREATE TABLE Journey_Client_Info
(
	Journey_id INT NOT NULL,
	Client_id INT NOT NULL,
	CONSTRAINT PK_JOURNEY_CLIENT_INFO PRIMARY KEY (Journey_id, Client_id),
	CONSTRAINT FK_JOURNEY_CLIENT_INFO_TO_JOURNEY FOREIGN KEY (Journey_id) REFERENCES Journey (Journey_id) ON DELETE CASCADE,
	CONSTRAINT FK_JOURNEY_CLIENT_INFO_TO_CLIENT_INFO FOREIGN KEY (Client_id) REFERENCES Client_Info (Client_id) ON DELETE CASCADE

)
CREATE TABLE Journey_Hotel
(
	Journey_id INT NOT NULL,
	Hotel_id INT NOT NULL,
	CONSTRAINT PK_JOURNEY_HOTEL PRIMARY KEY (Journey_id, Hotel_id),
	CONSTRAINT FK_JOURNEY_HOTEL_TO_HOTEL FOREIGN KEY (Hotel_id) REFERENCES Hotel (Hotel_id),
	CONSTRAINT FK_JOURNEY_HOTEL_TO_JOURNEY FOREIGN KEY (Journey_id) REFERENCES Journey (Journey_id) ON DELETE CASCADE

)
CREATE TABLE Phone_Number
(
	Phone_Number NVARCHAR(30) NOT NULL CONSTRAINT PK_PHONE_NUMBER PRIMARY KEY,
	Client_id INT,
	Excursion_Company_id INT,
	Hotel_id INT,
	CONSTRAINT FK_PHONE_NUMBER_TO_CLIENT_INFO FOREIGN KEY (Client_id) REFERENCES Client_info (Client_id) ON DELETE CASCADE,
	CONSTRAINT FK_PHONE_NUMBER_TO_EXCURSION_COMPANY FOREIGN KEY (Excursion_Company_id) REFERENCES Excursion_Company (Excursion_Company_id),
	CONSTRAINT FK_PHONE_NUMBER_TO_HOTEL FOREIGN KEY (Hotel_id) REFERENCES Hotel (Hotel_id)
)