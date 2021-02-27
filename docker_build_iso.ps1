$dir = pwd
$dir = [Management.Automation.WildcardPattern]::Escape($dir)
docker run -v ${dir}:/root/env --env build_arg=build-x86_64 --rm sossos-buildenv