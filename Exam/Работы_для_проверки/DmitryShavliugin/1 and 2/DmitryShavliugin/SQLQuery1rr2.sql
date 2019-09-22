CREATE DATABASE mssql_testdb_l05_33pr11 

CREATE TABLE Manufacturer
(
Id INT IDENTITY ,
Name NVARCHAR(50)

CONSTRAINT PK_Manufacturer_Id PRIMARY KEY (Id)
)

INSERT INTO
Manufacturer(Name)
VALUES 
('��������� ������'),
('������ ���� ��������'),
('������� �����'),
('�������� ��������'),
('������ �������'),
('Samsung'),
('LG'),
('�����'),
('������')

CREATE TABLE Customers 
(
Id INT IDENTITY,
Name NVARCHAR(50)

CONSTRAINT PK_Customers_Id PRIMARY KEY (Id)
)

INSERT INTO
Customers(Name)
VALUES 
('����'),
('����'),
('���������'),
('������'),
('�������'),
('���'),
('������'),
('����')


CREATE TABLE Products 
(
Id INT IDENTITY,
Name NVARCHAR(10),
Id_Manufacturer INT,
ProductCount INT,
Price MONEY,

CONSTRAINT PK_Products_Id PRIMARY KEY (Id),
CONSTRAINT FK_Products_To_Manufacturer FOREIGN KEY (Id_Manufacturer)  REFERENCES Manufacturer (Id)
)

INSERT INTO Products
(Name, Id_Manufacturer, ProductCount, Price)
VALUES
('�����', (SELECT Id FROM Manufacturer  WHERE Name ='��������� ������'), 100, 50),
('����', (SELECT Id FROM Manufacturer  WHERE Name ='������ ���� ��������'), 15, 45),
('������', (SELECT Id FROM Manufacturer  WHERE Name ='������� �����'), 500, 20),
('������', (SELECT Id FROM Manufacturer  WHERE Name ='�������� ��������'), 333, 70),
('��������', (SELECT Id FROM Manufacturer  WHERE Name ='������ �������'), 1000, 15),
('������', (SELECT Id FROM Manufacturer  WHERE Name ='������ ���� ��������'), 456, 15),
('�������', (SELECT Id FROM Manufacturer  WHERE Name ='������ ���� ��������'), 35, 23),
('�����', (SELECT Id FROM Manufacturer  WHERE Name ='������� �����'), 20, 18),
('�������', (SELECT Id FROM Manufacturer  WHERE Name ='������'), 55, 100)


CREATE TABLE Orders 
(
Id INT IDENTITY,
CreatedAt DATE,
ProductId INT, 
CustomerId INT,
ProductCount INT,
Price MONEY

CONSTRAINT PK_Orders_Id PRIMARY KEY (Id),
CONSTRAINT FK_Orders_To_Customers FOREIGN KEY (CustomerId)  REFERENCES Customers (Id),
CONSTRAINT FK_Orders_To_Products FOREIGN KEY (ProductId)  REFERENCES Products (Id),
)


INSERT INTO Orders
(CreatedAt, ProductId,CustomerId,ProductCount,Price)
VALUES

( '01-09-2019',
(SELECT Id FROM Products WHERE Name ='�����'),
(SELECT Id FROM Customers WHERE Name ='����'),
2,
(SELECT Price FROM Products WHERE Name ='�����')
),

( '2019-08-31',
(SELECT Id FROM Products WHERE Name ='����'),
(SELECT Id FROM Customers WHERE Name ='����'),
1,
(SELECT Price FROM Products WHERE Name ='����')
),

( '2019-08-30', 
(SELECT Id FROM Products WHERE Name ='������'),
(SELECT Id FROM Customers WHERE Name ='�������'),
5,
(SELECT Price FROM Products WHERE Name ='������')
),

( '2019-08-29',
(SELECT Id FROM Products WHERE Name ='������'),
(SELECT Id FROM Customers WHERE Name ='������'),
3,
(SELECT Price FROM Products WHERE Name ='������')
),

( '2019-09-02',
(SELECT Id FROM Products WHERE Name ='��������'),
(SELECT Id FROM Customers WHERE Name ='���������'),
11,
(SELECT Price FROM Products WHERE Name ='��������')
),

( '2019-09-03',
(SELECT Id FROM Products WHERE Name ='�������'),
(SELECT Id FROM Customers WHERE Name ='������'),
9,
(SELECT Price FROM Products WHERE Name ='��������')
),

( '2019-08-31',
(SELECT Id FROM Products WHERE Name ='������'),
(SELECT Id FROM Customers WHERE Name ='������'),
4,
(SELECT Price FROM Products WHERE Name ='������')
),

( '2019-08-29',
(SELECT Id FROM Products WHERE Name ='�����'),
(SELECT Id FROM Customers WHERE Name ='�������'),
6,
(SELECT Price FROM Products WHERE Name ='�����')
)


select * from Products p, Manufacturer m, Orders o, Customers c
where
p.Id_Manufacturer= m.Id
and
o.ProductId = p.Id
and 
o.CustomerId = c.Id

select o.*,c.*
from
	Products p, Manufacturer m,
	Orders o, Customers c
where
p.Id_Manufacturer = m.Id
and
o.ProductId = p.Id
and
o.CustomerId = c.Id

select o.*, c.Name, p.Name, m.Name				-- .* ????
	from Orders o
	inner join Customers c 
		on c.Id =  o.CustomerId			--inner join vs join vs outer (left join, right join) vs full join vs cross
	join Products p
		on o.ProductId = p.Id
	join Manufacturer m
		on p.Id_Manufacturer = m.Id
where
	p.Name = '�����'


select o.*, c.Name
	from Orders o
	Full join Customers c 
		on c.Id =  o.CustomerId

select 1 as typeCotrAgent, m.Name
from Manufacturer m
Union								--union vs union all
select 2 as typeCotrAgent,
	   c.Name		
from Customers c
order by 1							--sort