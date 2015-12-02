/*

 */
function change_dog_status()
{
   var ret =  confirm("您确定关闭路由认证？");
   
   if(!ret)
     return;
   $.ajax({
            type: "POST",
            url: "/cgi-bin/routerSettings",
            data: {
                form_id: "set_dogstat",
		stat: $("#dog_stat").val(),
            },
            beforeSend: function () { },
            dataType: "json",
            success: function (data) { 
	      var ret = eval(data);
	      if(ret.result == 0){
		alter("OK: 设置成功！");
		return;
	      }
	      alter("ERROR: 设置失败！");
             }
        });
}

function load_dogstat()
{
     $.ajax({
            type: "POST",
            url: "/cgi-bin/routerSettings",
            data: {
                form_id: "data_dogstat",
            },
            beforeSend: function () { },
            dataType: "json",
            success: function (data) { 
	      var ret = eval(data);
	      if(ret.result == 1)
		alter("dog is alive !");
	      else
		alter("dog is down !");
             }
        });
}