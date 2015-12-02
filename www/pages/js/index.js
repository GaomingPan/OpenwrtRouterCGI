$("#wifi_passwd_box").click(function () {

    if ($("#wifi_passwd_box").is(":checked")) {
        $("#objPage1 > .div-item").css("visibility", "hidden");
        $("#objPage1 > .div-item").css("display", "none");
        $("#objPage1 > #div3").css("visibility", "visible");
        $("#objPage1 > #div3").css("display", "block");

    }
    else {

        $("#objPage1 > .div-item").css("visibility", "hidden");
        $("#objPage1 > .div-item").css("display", "none");
        $("#objPage1 > #div3").css("visibility", "hidden");
        $("#objPage1 > #div3").css("display", "none");
    }


});
$("#check_frame").click(function () {
    if ($("#wifi").is(":checked")) {
        $("#objPage > .div-item").css("visibility", "hidden");
        $("#objPage > .div-item").css("display", "none");
        $("#objPage > #div2").css("visibility", "visible");
        $("#objPage > #div2").css("display", "block");

    }
    else {

        $("#objPage > .div-item").css("visibility", "hidden");
        $("#objPage > .div-item").css("display", "none");
        $("#objPage > #div2").css("visibility", "hidden");
        $("#objPage > #div2").css("display", "none");
    }


});


$("#auth_check").click(function () {
    if ($("#auth_check").is(":checked"))
        $("#auth_txt").html("认 证 上 网 打 开");
    else
        $("#auth_txt").html("认 证 上 网 关 闭");

});