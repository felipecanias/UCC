package model

import (
	"github.com/google/uuid"
)

type Photo struct {
	PhotoID uuid.UUID `bson:"PhotoID"`
	Url     string    `bson:"Url"`
}

type Photos []Photo

// func (photo *Photo) BeforeCreate(scope *gorm.Scope) error {
// 	return scope.SetColumn("PhotoID", uuid.New())
// }
