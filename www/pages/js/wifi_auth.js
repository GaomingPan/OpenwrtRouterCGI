function auth_data_binding() {

    $.ajax({
        type: "POST",
        url: "/cgi-bin/routerSettings",
        data: {
            form_id: "data_dogstat"
        },
        dataType: "json",
        beforeSend: function () {

        },
        success: function (data) {

            var ret = eval(data);
            if (ret.result == 0) {

                if (ret.stat == 0) {
                    if (!$("#auth_check").is(":checked")) {
                        $("#auth_check").attr("checked", true);
                        $("#auth_txt").html("认 证 上 网 打 开");
                    }
                } else {

                    if ($("#auth_check").is(":checked")) {
                        $("#auth_check").attr("checked", false);
                    }
                    $("#auth_txt").html("认 证 上 网 关 闭");
                }

            } else {
                alert("ERROR: 内部错误！");
                window.location = "/index.html";
            }

        }//success
    });//$.ajax
}


function auth_data_post() {

    var stat;

    if ($("#auth_check").is(":checked"))
        stat = 0;
    else
        stat = 1;


    $.ajax({
        type: "POST",
        url: "/cgi-bin/routerSettings",
        data: {
            form_id: "set_dogstat",
            stat: stat,
        },
        dataType: "json",
        beforeSend: function () {

        },
        success: function (data) {

            var ret = eval(data);
            if (ret.result == 0) {
              //  alert("OK: 无线认证设置成功！");
             //   window.location = "/index.html";
            } else {
                alert("ERROR: 设置出错！请重新设置！");
                window.location = "/index.html";
            }

        },//success
    });//$.ajax
}