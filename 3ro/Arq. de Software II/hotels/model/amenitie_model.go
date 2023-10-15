package model

import (
	"github.com/google/uuid"
)

type Amenity struct {
	AmenityID uuid.UUID `bson:"AmenityID"`
	Title      string    `bson:"Title"`
}

type Amenities []Amenity

// func (amenitie *Amenitie) BeforeCreate(scope *gorm.Scope) error {
// 	return scope.SetColumn("AmenitieID", uuid.New())
// }
