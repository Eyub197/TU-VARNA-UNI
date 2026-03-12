def generate_passwords():
    n = int(input("Enter n (1-9): "))
    m = int(input("Enter m (1-26): "))

    for s1 in range(1, n + 1):
        for s2 in range(1, n + 1):
            for s3_code in range(97, 97 + m):
                s3 = chr(s3_code)
                for s4_code in range(97, 97 + m):
                    s4 = chr(s4_code)
                    start_s5 = max(s1, s2) + 1
                    for s5 in range(start_s5, n + 1):
                        print(f"{s1}{s2}{s3}{s4}{s5}", end=" ")


# Run the function
generate_passwords()
