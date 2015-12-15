/*

 */

function change_password() {
    var ret = confirm("您确定修改您的管理员用户名或密码？");

    if (!ret)
        return false;

    if($("#username") == ""){

        alert("ERROR: 用户名不能为空！");
        return false;
    }

    if ($("#pwd1").val() != $("#pwd2").val()) {
        alert("ERROR: 您两次输入的密码不一致！");
        return false;
    }

    $.ajax({
        type: "POST",
        url: "/cgi-bin/routerSettings",
        data: {
            form_id: "set_admin",
            username: $("#username").val(),
            password: $("#pwd1").val(),
        },
        beforeSend: function () {
        },
        dataType: "json",
        success: function (data) {
            var ret = eval(data);
            if (ret.result == 0) {
                alert("OK: 您的用户名和密码修改成功！");
                window.location = "/index.html";
            } else {
                alert("ERROR: 您的用户名和密码修改失败");
                window.location = "/index.html";
            }
        },
    });
    return true;
}


function load_admin_info() {

    $.ajax({
        type: "POST",
        url: "/cgi-bin/routerSettings",
        data: {
            form_id: "data_admin",
        },
        beforeSend: function () {
        },
        dataType: "json",
        success: function (data) {
            var ret = eval(data);
            if (ret.result == 0) {

                $("#username").val(ret.username);
            } else
                window.location = "/index.html";
        }
    });
}




