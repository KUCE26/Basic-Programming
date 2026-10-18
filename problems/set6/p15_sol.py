def BMI(body_info):
    h = body_info["신장"] / 100
    w = body_info["체중"]
    return round(w / (h ** 2), 2)


body_data = {
    "신장": int(input()),
    "체중": int(input())
}

print("BMI :", BMI(body_data))
