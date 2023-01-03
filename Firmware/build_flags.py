import subprocess

from datetime import date


today = date.today()

revision = (
    subprocess.check_output(
        [
            "git",
            "describe",
            "--abbrev=8",
            "--dirty",
            "--always",
            "--tags",
        ]
    )
    .strip()
    .decode("utf-8")
)

host = (
    subprocess.check_output(
        [
            "hostname",
        ]
    )
    .strip()
    .decode("utf-8")
)

username = (
    subprocess.check_output(
        [
            "id",
            "-u",
            "-n",
        ]
    )
    .strip()
    .decode("utf-8")
)

# Cleanup CI
if username == "root":
    username = "github"
    host = "github"

# Colors!
revision = revision.replace("dirty", "\x1B[31mdirty\x1B[0m")
host = "\x1B[34m" + host + "\x1B[0m"
username = "\x1B[34m" + username + "\x1B[0m"


motd = f"\\r\\nStarting pendulum demo.\\r\\nThis software expects your terminal to be \x1B[46mVT100 Compatable\x1B[0m,\\r\\n\\r\\nUsing version {revision}.\\r\\ncompiled on {today.strftime('%B %d, %Y')} by {username} using {host}.\\r\\n\\r\\n"

print(f"-DMOTD='\"{motd}\"'")
