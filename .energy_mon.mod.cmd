savedcmd_energy_mon.mod := printf '%s\n'   energy_mon.o | awk '!x[$$0]++ { print("./"$$0) }' > energy_mon.mod
