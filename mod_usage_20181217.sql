-----造数据，更新表
-----偶数行的result,type列修改默认值 \
-----mod 用法
declare 
cursor s1 is select * from tagentcalltransfer;
srow   tagentcalltransfer%rowtype;
n   number:=0;
begin 
  open s1;
  loop
    n := n + 1;
     dbms_output.put_line(n);
    fetch s1 into    srow ;
    exit when s1%notfound;
      if mod(n,2)  = 0 then  
        dbms_output.put_line('update :' || n);
       update tagentcalltransfer t set t.c_result = 2,t.l_type = 2 where t.l_serialno = srow.l_serialno;
       commit;
      end if;
  end loop;
end;
/
