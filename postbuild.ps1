Copy-Item "*.dll*" -Destination "../go"
cd ../go
go build -o App.so -buildmode=c-shared