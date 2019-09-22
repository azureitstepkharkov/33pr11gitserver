CREATE DATABASE mssql_testdb_105_33pr11
	

go
use mssql_testdb_105_33pr11;
go

CREATE TABLE Manufacturers
(
    Id INT IDENTITY PRIMARY KEY,
    Nameof NVARCHAR(50) NOT NULL,
)

insert into Manufacturers
values 
('��������� ������'),
('������ ���� ��������'),
('������� ����a'),
('�������� ��������'),
('������ �������'),
('Samsung'),
('Lg'),
('Roshen'),
('������');

create table Customers(
	Id INT IDENTITY PRIMARY KEY,
    NameofCustomer NVARCHAR(50) NOT NULL,
);

insert into Customers
values 
('����'),
('����'),
('���������'),
('������'),
('������'),
('���'),
('������'),
('����');


create table Products(
	IdOfProduct INT IDENTITY PRIMARY KEY,
	NameOfProduct NVARCHAR(50) NOT NULL,
	IdOfManufacturers int NOT NULL,
	Quantity int,
	Price money,
	
	foreign key (IdOfManufacturers) references Manufacturers(Id)
);

insert into Products
values 
('�����',1,100,50),
('����',2,15,45),
('������',3,500,20),
('������',4,333,70),
('��������',5,1000,15),
('������',2,456,15),
('��������',2,35,23),
('�����',3,20,18),
('�������',9,55,100);

create table Orders (
	Id INT IDENTITY PRIMARY KEY,
	CreatedAt date,
	ProductId int,
	CustomerId int,
	ProductCount int, 
	Price money,
	
	foreign key (ProductId) references Products(IdOfProduct),
	foreign key (CustomerId) references Customers(Id)	
);


select * from Orders;
select * from Manufacturers;
select * from Customers;
select * from Products;


select * from Products p, Manufacturers m, Orders o
where
p.IdOfManufacturers= m.Id
and
o.ProductId = p.Id
and 
o.CustomerId = c.Id

select o.*,c.*
from
	Products p, Manufacturers m,
	Orders o, Customers c
where
p.ManufacturerId = m.Id
and
o.ProductId = p.Id
and
o.CustomerId = c.Id


drop database mssql_testdb_105_33pr11;
