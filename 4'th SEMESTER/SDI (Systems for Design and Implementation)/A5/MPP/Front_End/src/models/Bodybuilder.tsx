export interface Bodybuilder {
    id?: number;
    name: string;
    age: number;
    weight: number;
    height: number;
    division: string;
    [key: string]: any;
}