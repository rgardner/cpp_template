import subprocess

subprocess.run(["git", "init"], check=True)
subprocess.run(["git", "commit", "-m", "Initial commit", "--allow-empty"], check=True)
subprocess.run(
    [
        "git",
        "submodule",
        "add",
        "https://github.com/Microsoft/vcpkg.git",
        "external/vcpkg",
    ],
    check=True,
)
subprocess.run(["git", "add", "*"], check=True)
subprocess.run(["git", "commit", "-m", "Add files"], check=True)
subprocess.run(["just", "setup", "fmt"], check=True)
subprocess.run(["git", "commit", "--all", "--amend", "--no-edit"], check=True)
