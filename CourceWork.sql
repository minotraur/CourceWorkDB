1 ------------------------------------------------------

create table "Groups"
(
	id_group serial not null primary key,
	amount_of_students int not null,
	group_name varchar(20) not null,
	specialization varchar(20) not null
);

2 ------------------------------------------------------

create table "Auditoriums"
(
	id_auditorium int not null primary key,
	capacity int not null,
	number_auditorium int not null,
	equipment_available varchar(20) not null,
	name_of_auditorium varchar(20) not null,
	constraint auditoriums_number_fk
	foreign key (number_auditorium)
	references "Auditoriums"(id_auditorium)
);
3 ------------------------------------------------------

create table "Teachers"
(
	id_teacher serial not null primary key,
	last_name varchar(20) not null,
	first_name varchar(20) not null,
	middle_name varchar(20) not null,
	id_group int not null,
	faculty varchar(100) not null,
	constraint teachers_fk
	foreign key (id_group)
	references "Groups"(id_group)
);

4 ------------------------------------------------------

create table "Schedule"
(
	id_schedule serial not null primary key,
	id_teacher int not null,
	pair_number int not null,
	id_auditorium int not null,
	type_of_work varchar(20) not null,
	discipline varchar(60) not null,
	constraint from_teacher_to_schedule_k
	foreign key (id_teacher) 
	references "Teachers"(id_teacher),
	constraint from_auditorium_to_schedule_k
	foreign key (id_auditorium)
	references "Auditoriums"(id_auditorium)
);
	
------------------------------------------------------

Заполнение ----------------------------------------------------------------------------------------------------------------------

INSERT INTO public."Groups" (id_group, amount_of_students, group_name, specialization)
VALUES (DEFAULT, 28, 'БСБО-01-19', 'Программист'),
		(DEFAULT, 29, 'БСБО-02-19', 'Программист'),
		(DEFAULT, 30, 'БСБО-04-19', 'Сетевой инженер'),
		(DEFAULT, 35, 'БСБО-05-20', 'Machine Learning'),
		(DEFAULT, 20, 'БСБО-06-18', 'Менеджер'),
		(DEFAULT, 18, 'БСБО-07-21', 'Физик'),
		(DEFAULT, 16, 'БСБО-08-16', 'Программист'),
		(DEFAULT, 24, 'КБСП-01-19', 'Программист'),
		(DEFAULT, 26, 'БАСО-03-17', 'Программист'),
		(DEFAULT, 15, 'БОСА-04-20', 'Сетевой инженер'),
		(DEFAULT, 29, 'БАКС-20-19', 'Программист'),
		(DEFAULT, 30, 'АСКЕ-31-12', 'Machine Learning'),
		(DEFAULT, 30, 'ВБРЕ-19-20', 'Веб-разработчик'),
		(DEFAULT, 31, 'ФЗКА-15-22', 'Физик'),
		(DEFAULT, 32, 'БББИ-12-21', 'Биолог'),
		(DEFAULT, 32, 'ББББ-13-19', 'Математик'),
		(DEFAULT, 32, 'ЛИНГ-12-21', 'Лингвист');

INSERT INTO public."Auditoriums" (id_auditorium, capacity, number_auditorium, equipment_available, name_of_auditorium)
VALUES (1, 60, 1, 'Да', 'П-34'),
		(2, 70, 2, 'Нет', 'Л-30'),
		(3, 100, 3, 'Нет', 'К-4'),
		(4, 11, 4, 'Да', 'РА-4'),
		(5, 20, 5, 'Да', 'КБ-4'),
		(6, 28, 6, 'Да', 'КБ-5'),
		(7, 37, 7, 'Да', 'КБ-6'),
		(8, 50, 8, 'Нет', 'У-34'),
		(9, 50, 9, 'Да', 'А-1'),
		(10, 31, 10, 'Нет', 'А-2'),
		(11, 18, 11, 'Да', 'Б-43'),
		(12, 56, 12, 'Нет', 'В-5'),
		(13, 30, 13, 'Да', 'Б-44'),
		(14, 41, 14, 'Нет', 'В-6'),
		(15, 46, 15, 'Да', 'Б-45'),
		(16, 50, 16, 'Нет', 'В-7'),
		(17, 30, 17, 'Да', 'Б-46'),
		(18, 50, 18, 'Нет', 'А-10'),
		(19, 50, 19, 'Да', 'А-11'),
		(20, 70, 20, 'Нет', 'А-12'),
		(21, 70, 21, 'Да', 'А-13'),
		(22, 70, 22, 'Нет', 'А-14'),
		(23, 22, 23, 'Да', 'Е-3'),
		(24, 20, 24, 'Нет', 'Е-9'),
		(25, 10, 25, 'Да', 'У-4'),
		(26, 60, 26, 'Нет', 'Е-15'),
		(27, 22, 27, 'Да', 'Е-21'),
		(28, 20, 28, 'Нет', 'У-5'),
		(29, 40, 29, 'Да', 'Е-27'),
		(30, 46, 30, 'Нет', 'Е-33');
		
		
INSERT INTO public."Teachers" (id_teacher, last_name, first_name, middle_name, id_group, faculty)
VALUES (DEFAULT, 'Филатов', 'Вячеслав', 'Валерьевич', 3, 'Прикладные информационные технологии'),
		(DEFAULT, 'Кашкин', 'Евгений', 'Владимирович', 2, 'Интеллектуальные системы информационной безопасности'),
		(DEFAULT, 'Беклемишев', 'Сергей', 'Андреевич', 1, 'Высшая математика'),
		(DEFAULT, 'Пыркин', 'Андрей', 'Генадьевич', 4, 'Физика'),
		(DEFAULT, 'Алексеенко', 'Анна', 'Сергеевна', 8, 'Интеллектуальные системы информационной безопасности'),
		(DEFAULT, 'Кульков', 'Дмитрий', 'Александрович', 7, 'Прикладные информационные технологии'),
		(DEFAULT, 'Абышев', 'Станислав', 'Владимирович', 11, 'Кафедра систем связи и телекоммуникаций'),
		(DEFAULT, 'Авдижиян', 'Артур', 'Юрьевич', 14, 'Физика'),
		(DEFAULT, 'Автоношкин', 'Иван', 'Николаевич', 5, 'Управление кадров'),
		(DEFAULT, 'Агафонов', 'Алексей', 'Николаевич', 9, 'Компьютерная и информационная безопасность'),
		(DEFAULT, 'Агапов', 'Павел', 'Валерьевич', 5, 'Уголовно-правовое обеспечение национальной безопасности'),
		(DEFAULT, 'Адамович', 'Ольга', 'Маратовна', 16, 'Высшая математика'),
		(DEFAULT, 'Харьковский', 'Станислав', 'Евгеньевич', 13, 'Промышленная информатика'),
		(DEFAULT, 'Хачикян', 'Анна', 'Давидовна', 17, 'Международное образование');

		
INSERT INTO public."Schedule" (id_schedule, id_teacher, pair_number, id_auditorium, type_of_work, discipline)
VALUES (DEFAULT, 2, 1, 1, 'Практика', 'Программирование'),
		(DEFAULT, 3, 2, 2, 'Лекция', 'Математический анализ'),
		(DEFAULT, 2, 3, 1, 'Практика', 'Программирование'),
		(DEFAULT, 6, 4, 4, 'Практика', 'Базы данных'),
		(DEFAULT, 4, 3, 2, 'Практика', 'Физика'),
		(DEFAULT, 3, 1, 8, 'Лекция', 'Высшая математика'),
		(DEFAULT, 2, 1, 1, 'Лекция', 'Программирование'),
		(DEFAULT, 4, 1, 7, 'Практика', 'Базы данных'),
		(DEFAULT, 1, 5, 5, 'Лекция', 'Сложность алгоритмов');


---------------------------------------------------------------------------------------------------------------------------------

-- запрос на поиск свободных аудиторий -------------------------------------------

select "Auditoriums".id_auditorium as "Свободные аудитории"
from "Auditoriums"
left join "Schedule"
on "Auditoriums".id_auditorium = "Schedule".id_auditorium
where "Schedule".id_auditorium is null

--------------------------------------------------------------------------------
	
--- Составной многотабличный запрос с параметром, включающий соединение таблиц и CASE-выражение	---
-------------------------------------------------------------------------------------------		

select g.group_name as "Название группы", g.amount_of_students as "Количество студентов", g.specialization as "Специальность",
	case
		when g.specialization = 'Программист' then (
			select last_name as "Имя учителя"
			from "Teachers" t1
			inner join "Groups" g2
			on g2.id_group = t1.id_group
			where (faculty = 'Прикладные информационные технологии' or faculty = 'Интеллектуальные системы информационной безопасности' or faculty = 'Компьютерная и информационная безопасность' or faculty = 'Кафедра систем связи и телекоммуникаций') and g.id_group = t1.id_teacher
		)
		when g.specialization <> 'Программист' then 'Эта группа не относится к программистам'
		when g.specialization is null then 'Эта группа не закреплена за преподавателем'
	end "Преподватель для группы"
from "Groups" g

----------------------------------------------------------------------------------------------		

--- На основе обновляющего представления (многотабличного VIEW), в котором критерий упорядоченности задает пользоваель при выполнении ---
------------------------------------------------------------------------------------------------------------------------------------

create or replace view upd_view as
select a.capacity as "Вместимость", a.number_auditorium as "Номер аудитории", a.name_of_auditorium as "Название аудитории", t.last_name as "Фамилия преподавателя"
from "Auditoriums" a join "Teachers" t on a.id_auditorium = t.id_teacher
where (a.id_auditorium = t.id_teacher)and(a.capacity in
		(select a.capacity
		 from "Auditoriums"
		where a.capacity >= 25));

select * from upd_view;

create or replace function update_upd_view()
returns  trigger as
$update_upd_view$
    begin
        if(new.Capacity != old.Capacity)
            then update "Auditoriums" set capacity = new.Capacity where id_auditorium = old.view_id;
        end if;
        if(new.NumberAuditorium != old.NumberAuditorium)
            then update "Auditoriums" set number_auditorium = new.NumberAuditorium where "Auditoriums".number_auditorium = old.view_id;
        end if;
        if(new.NameAudi != old.NameAudi)
            then update "Auditoriums" set name_of_auditorium = new.NameAudi where "Auditoriums".name_of_auditorium = old.view_id;
        end if;
        if(new.Educator != old.Educator)
            then update "Teachers" set last_name = new.Educator where "Teachers".last_name = old.view_id;
        end if;
    end;
$update_upd_view$
language plpgsql;

create trigger upd_view_trigger
instead of update on upd_view
for each row
    execute procedure update_upd_view();

update upd_view set NameAudi = 'Second' where NameAudi = 'Вторая';
update "Teachers" set last_name = 'Путин' where id_teacher = 1
------------------------------------------------------------------------------------------------------------------------------------
	
--- Запрос, содержащий коррелированные и некоррелированные подзапросы в разделах SELECT, FROM и WHERE (в каждом хотя бы по одному) ---
--- Выводит из таблицы "Groups" фамилию, имя, название группы и выводит только тех преподавателей которые не привязаны к группе БСБО-03-19 ---
------------------------------------------------------------------------------------------------------------------------------------

select t.last_name as "Фамилия", t.first_name as "Имя",
       (
        select group_name
        from "Groups" g
        where g.id_group = t.id_group
       ) as "Название группы"
from (select * from "Teachers") t, "Auditoriums" a
where t.id_teacher in (
    select id_group
    from "Groups"
    where group_name != 'БСБО-03-19') and (t.id_teacher = a.id_auditorium);
	

--- коррелированный в select
select t.last_name as "Фамилия", t.first_name as "Имя",
       (
        select group_name
        from "Groups" g
        where g.id_group = t.id_group
       ) as "Название группы"
from "Teachers" t

--- коррелированный в where 
select t.last_name, t.first_name
from "Teachers" t
where EXISTS(select * from "Groups" g where g.id_group = t.id_group and g.amount_of_students > 30)

--- некоррелированный в select
select a.capacity, (select specialization from "Groups" where group_name = 'БСБО-03-19')
from "Auditoriums" a
where a.name_of_auditorium = 'В-6'


--- некоррелированный в where
select distinct s.pair_number, s.discipline, s.type_of_work
from "Schedule" s join "Teachers" t on s.id_schedule = t.id_teacher
where t.faculty = 'Физика' and t.id_teacher = (select s1.id_schedule from "Schedule" s1)

 
--- некоррелированный в from
select g1.group_name, g1.amount_of_students
from (select g.group_name, g.amount_of_students from "Groups" g where g.group_name = 'КБСП-01-19') g1




------------------------------------------------------------------------------------------------------------------------------------

--- Многотабличный запрос, содержащий группировку записей, агрегативные функции и параметр, используемый в разделе HAVING ---
--- Выводит из таблицы Аудитории сумму вместимости в аудиториях в которых есть оборудование и нет ---
------------------------------------------------------------------------------------------------------------------------------------

select s.pair_number as "Номер пары", a.number_auditorium as "Номер аудитории", s.type_of_work as "Вид занятия", max(a.capacity) as "Вместимость"
from "Auditoriums" a, "Schedule" s
where s.id_auditorium = a.number_auditorium
group by s.pair_number, a.number_auditorium, s.type_of_work, a.capacity
having max(a.capacity) >= 30

------------------------------------------------------------------------------------------------------------------------------------

--- Запрос, содержащий предикат ANY, SOME или ALL ---
--- Выводит из таблицы Группы только те группы если в таблице группы есть одинаковая специализация  ---
------------------------------------------------------------------------------------------------------------------------------------

select g.amount_of_students as "Количество студентов", g.group_name as "Название группы", g.specialization as "Специализация"
from "Groups" g
where specialization = any (
    select specialization
    from "Groups" g1
    where g1.id_group<>g.id_group
    )

------------------------------------------------------------------------------------------------------------------------------------

--- создание индексов ---
------------------------------------------------------------------------------------------------------------------------------------

create index audit_index
on "Auditoriums" (number_auditorium);
create index sche_index
on "Schedule" (id_teacher, id_auditorium);
create index teach_index
on "Teachers" (id_group);



create index audit_index
on "Auditoriums" (capacity, equipment_available, name_of_auditorium);
create index sche_index
on "Schedule" (pair_number, type_of_work, discipline);
create index teach_index
on "Teachers" (last_name, first_name, middle_name, faculty);

create index group_index
on "Groups" (amount_of_students, group_name, specialization);

------------------------------------------------------------------------------------------------------------------------------------


--- триггер на Auditoriums ---
------------------------------------------------------------------------------------------------------------------------------------

create table trigger_list(id serial not null primary key, someInfo varchar(150))
select * from trigger_list
select * from "Auditoriums"

create trigger trigger_audit
after insert or update or delete on "Auditoriums"
for each row execute procedure add_to_trigger_list();

CREATE OR REPLACE FUNCTION add_to_trigger_list() RETURNS TRIGGER AS $$
DECLARE
    eventOf varchar(30);
    addedOf varchar(100);
    messageOf varchar(150);
BEGIN
    IF    TG_OP = 'INSERT' THEN
        addedOf = NEW.name_of_auditorium;
        eventOf := 'Add new auditorium ';
        messageOf := eventOf || addedOf;
        INSERT INTO trigger_list(someInfo)
		VALUES (messageOf);
        RETURN NEW;
    ELSIF TG_OP = 'UPDATE' THEN
        addedOf = NEW.name_of_auditorium;
        eventOf := 'Update auditorium ';
        messageOf := eventOf || addedOf;
        INSERT INTO trigger_list(someInfo)
		VALUES (messageOf);
        RETURN NEW;
    ELSIF TG_OP = 'DELETE' THEN
        addedOf = OLD.name_of_auditorium;
        eventOf := 'Remove auditorium ';
        messageOf := eventOf || addedOf;
		INSERT INTO trigger_list(someInfo)
		VALUES (messageOf);
        RETURN OLD;
    end if;
end;
$$ language plpgsql;

insert into "Auditoriums"(id_auditorium,capacity,number_auditorium,equipment_available, name_of_auditorium) VALUES (120,50,120,'Нет','Sixth')
select someInfo as "Инфомация об изменении таблицы" from trigger_list
------------------------------------------------------------------------------------------------------------------------------------

--- функции на добавление, обновление, удаление ---
------------------------------------------------------------------------------------------------------------------------------------

create procedure insert_auditoriums( id_auditorium integer, capacity integer, number_auditorium integer, equipment_available varchar(10), name_of_auditorium varchar(20))
language SQL
as $$
insert into "Auditoriums"(id_auditorium, capacity, number_auditorium, equipment_available, name_of_auditorium) values (id_auditorium, capacity, number_auditorium, equipment_available, name_of_auditorium);
$$;
create or replace procedure update_auditoriums
(uid integer, ucapacity integer, unumber integer, uequipment varchar(10), uname varchar(50))
language SQL
as $$
update "Auditoriums" set capacity = ucapacity, number_auditorium = unumber, equipment_available = uequipment, name_of_auditorium = uname where id_auditorium = uid
$$;
create procedure delete_auditoriums
(did integer)
language SQL
as $$
delete from "Auditoriums" where id_auditorium = did
$$;

call insert_auditoriums(7,25,7,1,'seventh');

call update_auditoriums(7,54,7,0,'eighth');

call delete_auditoriums(7);

SELECT * FROM "Auditoriums";

create procedure insert_groups( amount_of_students integer, group_name varchar(30), specialization varchar(50))
language SQL
as $$
insert into "Groups"(amount_of_students, group_name, specialization) values (amount_of_students, group_name, specialization);
$$;
create or replace procedure update_groups
(uid integer, uamount integer, ugroupname varchar(30), uspecialization varchar(50))
language SQL
as $$
update "Groups" set amount_of_students = uamount, group_name = ugroupname, specialization = uspecialization where id_group = uid
$$;
create procedure delete_groups
(did integer)
language SQL
as $$
delete from "Groups" where id_group = did
$$;

call insert_groups(335345,'Б01-19','МЕhОЛО');
call update_groups(9,335465,'БИСОы01-19','МЕМОЛОГИ');
call delete_groups(9);
SELECT * FROM "Groups";

create procedure insert_schedule(id_teacher integer, pair_number integer, id_auditorium integer, type_of_work varchar(20), discipline varchar(60))
language SQL
as $$
insert into "Schedule"(id_teacher, pair_number, id_auditorium, type_of_work, discipline) values (id_teacher, pair_number, id_auditorium, type_of_work, discipline);
$$;
create or replace procedure update_schedule
(uid integer, uidteacher integer, upairnum integer, uidauditorium integer, utypeofwork varchar(20), udiscipline varchar(60))
language SQL
as $$
update "Schedule" set id_teacher = uidteacher, pair_number = upairnum, id_auditorium = uidauditorium, type_of_work = utypeofwork, discipline = udiscipline where id_schedule = uid
$$;
create procedure delete_schedule
(did integer)
language SQL
as $$
delete from "Schedule" where id_schedule = did
$$;
call insert_schedule(3,1,3,'Практика','Астрология');
call update_schedule(3,3,3,'Практика','Астрология');
call delete_schedule(8);
select * from "Schedule";


create procedure insert_teacher(last_name varchar(20), first_name varchar(20), middle_name varchar(20), id_group integer, faculty varchar(100))
language SQL
as $$
insert into "Teachers"(last_name, first_name, middle_name, id_group,faculty) values (last_name, first_name, middle_name, id_group, faculty);
$$;
create or replace procedure update_teacher
(uid integer, ulastname varchar(20), ufirstname varchar(20), umiddlename varchar(20), uidgroup integer, ufacility varchar(100))
language SQL
as $$
update "Teachers" set last_name = ulastname, first_name = ufirstname, middle_name = umiddlename, id_group = uidgroup, faculty = ufacility where id_teacher = uid
$$;
create procedure delete_teacher
(did integer)
language SQL
as $$
delete from "Teachers" where id_teacher = did
$$;


call insert_teacher('qwe', 'asd', 'zxc', 3, 'qwerty');
call update_teacher(7 ,'QWE', 'ASD', 'ZXC', 3, 'qwerty');
call delete_teacher(9);
select * from "Teachers";

------------------------------------------------------------------------------------------------------------------------------------

--- Откатываемая процедура, удаляющая из всех таблиц строку с определённым ID, ---
--- но только, если строка с таким id есть в software ---
------------------------------------------------------------------------------------------------------------------------------------

create or replace procedure delete_rows(did integer) as $$
begin
if ((select id_schedule from "Schedule" where id_schedule = did)is not null) then
		delete from "Schedule" where id_schedule = did;
	else
		rollback;
    end if;
end;
$$ language plpgsql;

call delete_rows(6);
insert into "Schedule" (id_schedule, id_teacher, pair_number, id_auditorium, type_of_work, discipline) values (6,3,3,5,'Лекция','Астрология');
select * from "Schedule";

------------------------------------------------------------------------------------------------------------------------------------

--- Процедура с курсором на обновление ---
------------------------------------------------------------------------------------------------------------------------------------

create or replace procedure kursorProc
(uid integer, uamount integer, ugroupname varchar(50), uspecialization varchar(50)) AS $$
declare
	crs_my cursor for select * from "Groups";
	tempID integer;
	tempCAP integer;
	tempGROUP varchar(50);
	tempSPEC varchar(50);
begin
	open crs_my;
	loop
		fetch crs_my into tempID, tempCAP, tempGROUP, tempSPEC;
		if not FOUND then exit;end if;
		if(tempID = uid) then
			update "Groups" set amount_of_students = uamount,
			group_name = ugroupname, specialization = uspecialization where current of crs_my;
		end if;
	end loop;
end;
$$ language plpgsql;

call kursorProc(3,30,'БСБО-03-19','Программист');
select * from "Groups"

------------------------------------------------------------------------------------------------------------------------------------

--- Скалярная функция ---
------------------------------------------------------------------------------------------------------------------------------------

create or replace function TeacherId(tname varchar(50)) returns varchar AS $$
declare
tempID integer;
begin
	for tempID in select id_teacher from "Teachers" t where t.first_name = tname
	loop
		return tempID;
	end loop;
	return 'Преподавателя с таким именем нет в таблице';
end;
$$ language plpgsql;

select TeacherId('Андрей') as "Номер преподавателя"

------------------------------------------------------------------------------------------------------------------------------------

--- Вывести все аудитории в которых нет оборудования ---
------------------------------------------------------------------------------------------------------------------------------------
select a.number_auditorium as "Номер аудитории" FROM "Auditoriums" a WHERE a.equipment_available = 'Да';
------------------------------------------------------------------------------------------------------------------------------------

--- Векторная функция ---
------------------------------------------------------------------------------------------------------------------------------------
CREATE or REPLACE FUNCTION GroupsName(spec varchar(40))
RETURNS TABLE (group_name varchar(40), amount_of_students integer)
AS $$
BEGIN
	RETURN QUERY
		SELECT g.group_name, g.amount_of_students FROM "Groups" g
		WHERE g.specialization = spec;
END;
$$ LANGUAGE plpgsql;

select GroupsName('Программист') as "Информация о студентах"


SELECT * FROM "Groups"
------------------------------------------------------------------------------------------------------------------------------------


--- Создание обычного пользователя с доступом к таблицам ---
------------------------------------------------------------------------------------------------------------------------------------
create role mainuser LOGIN password '1234';
grant select on "Auditoriums" to mainuser;
grant select on "Groups" to mainuser;
grant select on "Schedule" to mainuser;
grant select on "Teachers" to mainuser;

--- Создание Админа ---
create role admin SUPERUSER LOGIN password '1234'
------------------------------------------------------------------------------------------------------------------------------------