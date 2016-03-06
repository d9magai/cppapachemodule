# cppapachemodule

```
sed -i -e 's/imagereceiver/helloworld/g' Makefile mod_imagereceiver.conf mod_imagereceiver.cpp
mv mod_imagereceiver.conf mod_helloworld.conf
mv mod_imagereceiver.cpp mod_helloworld.cpp 
sudo cp mod_helloworld.conf /etc/httpd/conf.d/.
make 
sudo apxs -A -i -a -n 'helloworld' mod_helloworld.so
```

