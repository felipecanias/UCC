package main

import "fmt"
import "go-api/items"
import "encoding/json"

func main(){

	item:= items.GetItem()
	
	jsonData, _ := json.MarshalIndent(*item, "", " ")

	fmt.Println(string(jsonData))
}