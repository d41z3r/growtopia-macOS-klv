std::string create_klv(std::string rid) {
    const std::string protocol = "191";
    const std::string game_version = "4.27";
    const std::string hash = "1431658473";

    constexpr std::array salts = {
        "832aac071ffbcfc15bfe1d0a7ad15221",
        "709296ddd04fc4074a7b443ecc0799aa",
        "623de1e8fff22a2b3e0d7e01593e7c22",
        "bb835e5a57e6c88e2449499ca487ced2",
        "ea76e4d6009282186063fe9465f2d9ab"
    };

    return GetMD5CheckSumAsString(GetMD5CheckSumAsString(GetMD5CheckSumAsString(game_version))
        + salts[0]
        + GetMD5CheckSumAsString(GetMD5CheckSumAsString(GetMD5CheckSumAsString(protocol)))
        + salts[1]
        + salts[2]
        + GetMD5CheckSumAsString(GetMD5CheckSumAsString(rid))
        + salts[3]
        + GetMD5CheckSumAsString(GetMD5CheckSumAsString(hash))
        + salts[4]
    );
}
