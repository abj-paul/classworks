import understand

# Use the correct path to your .und file
db = understand.open("/home/abhijit/Downloads/File-Transfer-and-Chat-Project-in-Java/Project Files.und")

# Example: Print the number of methods in each class
for ent in db.ents("class ~unknown ~unresolved"):
    print(f"{ent.name()}: {ent.metric('CountDeclMethod')}")
